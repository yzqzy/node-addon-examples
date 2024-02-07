#include <napi.h>

void RunCallback(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	if (!info[0].IsFunction()) {
		Napi::TypeError::New(env, "First argument must be a function")
		    .ThrowAsJavaScriptException();
		return;
	}
	Napi::Function cb = info[0].As<Napi::Function>();
	cb.Call(env.Global(), {Napi::String::New(env, "Hello, world!")});
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	return Napi::Function::New(env, RunCallback);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
