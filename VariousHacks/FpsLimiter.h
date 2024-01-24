#pragma once
#include <chrono>
#include <thread>

#include "ThirdParty/Injector/injector.hpp"
#include "Application.h"

int TargetFrameRate;

auto currentTime = std::chrono::high_resolution_clock::now();
auto lastFrameTime = currentTime;

bool __fastcall ProcessWinMessagesHook(m3d::Application* app)
{
	currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> deltaTime = currentTime - lastFrameTime;

	std::chrono::duration<double> targetFrameTime(1.0 / TargetFrameRate);
	if (deltaTime < targetFrameTime) {
		std::chrono::duration<double> sleepTime = targetFrameTime - deltaTime;
		std::this_thread::sleep_for(sleepTime);
	}

	lastFrameTime = std::chrono::high_resolution_clock::now();

	return app->ProcessWinMessages();
}

void InitFpsLimiter()
{
	injector::MakeCALL(0x005A7FB9, ProcessWinMessagesHook);
}