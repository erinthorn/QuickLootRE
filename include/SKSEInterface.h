#pragma once

#include "skse64/PapyrusEvents.h"  // SKSEModCallbackEvent, SKSECameraEvent, SKSECrosshairRefEvent, SKSEActionEvent, SKSENiNodeUpdateEvent
#include "skse64/gamethreads.h"  // TaskDelegate
#include "skse64/PluginAPI.h"  // SKSEInterface, PluginHandle, SKSEScaleformInterface, SKSEPapyrusInterface, SKSESerializationInterface, SKSETaskInterface, SKSEMessagingInterface, SKSEObjectInterface

#include <functional>  // function

#include "RE/BSTEvent.h"  // BSTEventSource


class SKSE
{
public:
	using TaskFn = std::function<void()>;


	static bool											Init(const SKSEInterface* a_skse);
	static PluginHandle									GetPluginHandle();
	static SKSEScaleformInterface*						GetScaleformInterface();
	static SKSEPapyrusInterface*						GetPapyrusInterface();
	static SKSESerializationInterface*					GetSerializationInterface();

	static SKSETaskInterface*							GetTaskInterface();
	static void											AddTask(TaskFn a_fn);
	static void											AddTask(TaskDelegate* a_delegate);
	static void											AddTask(UIDelegate_v1* a_delegate);

	static SKSEMessagingInterface*						GetMessagingInterface();
	static RE::BSTEventSource<SKSEModCallbackEvent>*	GetModCallbackEventSource();
	static RE::BSTEventSource<SKSECameraEvent>*			GetCameraEventSource();
	static RE::BSTEventSource<SKSECrosshairRefEvent>*	GetCrosshairRefEventSource();
	static RE::BSTEventSource<SKSEActionEvent>*			GetActionEventSource();
	static RE::BSTEventSource<SKSENiNodeUpdateEvent>*	GetNiNodeUpdateEventSource();

	static SKSEObjectInterface*							GetObjectInterface();

private:
	class Task : public TaskDelegate
	{
	public:
		Task(TaskFn a_fn) :
			_fn(a_fn)
		{}


		virtual void Run() override
		{
			_fn();
		}


		virtual void Dispose() override
		{
			delete this;
		}

	private:
		TaskFn _fn;
	};


	inline static PluginHandle									_pluginHandle = kPluginHandle_Invalid;
	inline static SKSEScaleformInterface*						_scaleformInterface = 0;
	inline static SKSEPapyrusInterface*							_papyrusInterface = 0;
	inline static SKSESerializationInterface*					_serializationInterface = 0;
	inline static SKSETaskInterface*							_taskInterface = 0;

	inline static SKSEMessagingInterface*						_messagingInterface = 0;
	inline static RE::BSTEventSource<SKSEModCallbackEvent>*		_modCallbackEventSource = 0;
	inline static RE::BSTEventSource<SKSECameraEvent>*			_cameraEventSource = 0;
	inline static RE::BSTEventSource<SKSECrosshairRefEvent>*	_crosshairRefEventSource = 0;
	inline static RE::BSTEventSource<SKSEActionEvent>*			_actionEventSource = 0;
	inline static RE::BSTEventSource<SKSENiNodeUpdateEvent>*	_niNodeUpdateEventSource = 0;

	inline static SKSEObjectInterface*							_objectInterface = 0;
};