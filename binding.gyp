{
    "targets": [
        {
            "target_name": "hello",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "sources": ["src/hello.cc"],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS'],
        },
        {
            "target_name": "math",
            "cflags!": ["-fno-exceptions"],
            "cflags_cc!": ["-fno-exceptions"],
            "sources": ["src/math.cc"],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS'],
        },
        {
            "target_name": "action_after_build",
            "type": "none",
            "dependencies": [
                "hello",
                'math',
                "<!(node -p \"require('node-addon-api').gyp\")"
            ],
            "copies": [
                {
                    "files": ["<(PRODUCT_DIR)/hello.node", "<(PRODUCT_DIR)/math.node"],
                    "destination": "./lib/binding"
                }
            ]
        }
    ]
}
