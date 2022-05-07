#include <napi.h>
#include "external/simdutf.cpp"
#include <node_api.h>
#include <memory>

Napi::Value Decode(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();

    return env.Null();
  }
  auto buf = info[0].As < Napi::Buffer < char >> ();

  return Napi::String::New(env, buf.Data(), buf.Length());
}

Napi::Value DecodeSimd(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();

    return env.Null();
  }
  auto buf = info[0].As < Napi::Buffer < char >> ();


  size_t expected_utf16words = simdutf::utf16_length_from_utf8(buf.Data(), buf.Length());

  if (expected_utf16words == buf.Length()) {
    // ascii
    // this route not using simd instructions on our side

    napi_value result;
    auto status = napi_create_string_latin1(env, buf.Data(), buf.Length(), &result);
    if (status != napi_ok) {
      Napi::TypeError::New(env, "create string failed")
              .ThrowAsJavaScriptException();
      return env.Null();
    }
    return Napi::Value(env, result);
  }

  std::unique_ptr < char16_t[] > utf16_output{new char16_t[expected_utf16words]};

  size_t utf16words = simdutf::convert_utf8_to_utf16(buf.Data(), buf.Length(), utf16_output.get());

  napi_value result;
  auto status = napi_create_string_utf16(env, utf16_output.get(), utf16words, &result);

  if (status != napi_ok) {
    Napi::TypeError::New(env, "create string failed")
            .ThrowAsJavaScriptException();

    return env.Null();
  }


  return Napi::Value(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {

  exports.Set(Napi::String::New(env, "decode"),
              Napi::Function::New(env, Decode));

  exports.Set(Napi::String::New(env, "decodeSimd"),
              Napi::Function::New(env, DecodeSimd));

  return exports;
}

NODE_API_MODULE(hello, Init)
