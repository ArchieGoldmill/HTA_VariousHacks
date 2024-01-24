#pragma once
#include <chrono>
#include <thread>

#include "ThirdParty/Injector/injector.hpp"
#include "Application.h"

int TargetFrameRate;

auto currentTime = std::chrono::high_resolution_clock::now();
auto lastFrameTime = currentTime;

int __fastcall OneFrameHook(m3d::Application* app)
{
	currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::ratio<1,1>> deltaTime = currentTime - lastFrameTime;

	std::chrono::duration<double, std::ratio<1, 1>> targetFrameTime(1.0f / TargetFrameRate);
	if (deltaTime < targetFrameTime) {
		std::chrono::duration<double, std::ratio<1, 1>> sleepTime = targetFrameTime - deltaTime;
		std::this_thread::sleep_for<double, std::ratio<1, 1>>(sleepTime);
	}

	lastFrameTime = std::chrono::high_resolution_clock::now();

	return app->OneFrame();
}

void InitFpsLimiter()
{
	injector::MakeCALL(0x005A8048, OneFrameHook);
}