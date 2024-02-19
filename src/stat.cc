#include <napi.h>
#include <regex>

Napi::Value Stat01(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  std::string str = info[0].As<Napi::String>().Utf8Value();

  int count = 0;
  double total_time = 0.0;

  auto start_time = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'o') { count++; }
  }

  auto end_time = std::chrono::high_resolution_clock::now();
  total_time = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count();

  Napi::Object result = Napi::Object::New(env);
  result.Set("count", count);
  result.Set("total_time", total_time);
  return result;
}

Napi::Value Stat02(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  std::string str = info[0].As<Napi::String>().Utf8Value();

  int count = 0;
  double total_time = 0.0;

  auto start_time = std::chrono::high_resolution_clock::now();

  int index = 0;
  while ((index = str.find('o', index)) != std::string::npos) {
    count++;
    index++;
  }

  auto end_time = std::chrono::high_resolution_clock::now();
  total_time = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count();

  Napi::Object result = Napi::Object::New(env);
  result.Set("count", count);
  result.Set("total_time", total_time);
  return result;
}

Napi::Value Stat03(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  std::string str = info[0].As<Napi::String>().Utf8Value();

  int count = 0;
  double total_time = 0.0;

  auto start_time = std::chrono::high_resolution_clock::now();

  std::regex pattern("o");
  std::sregex_iterator iter(str.begin(), str.end(), pattern);
  std::sregex_iterator end;

  while (iter != end) {
    count++;
    iter++;
  }

  auto end_time = std::chrono::high_resolution_clock::now();
  total_time = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count();

  Napi::Object result = Napi::Object::New(env);
  result.Set("count", count);
  result.Set("total_time", total_time);
  return result;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "stat01"), Napi::Function::New(env, Stat01));
  exports.Set(Napi::String::New(env, "stat02"), Napi::Function::New(env, Stat02));
  exports.Set(Napi::String::New(env, "stat03"), Napi::Function::New(env, Stat03));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
