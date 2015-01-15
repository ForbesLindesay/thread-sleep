{
  "targets": [
    {
      "target_name": "addon",
      "sources": [
        "addon.cc",
        "sync.cc"
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")"],
      "conditions": [
          [ 'OS=="mac"', {
              "xcode_settings": {
                  'OTHER_CPLUSPLUSFLAGS' : ['-std=c++11','-stdlib=libc++', '-v'],
                  'OTHER_LDFLAGS': ['-stdlib=libc++'],
                  'MACOSX_DEPLOYMENT_TARGET': '10.7',
                  'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
              }
          }]
      ]
    }
  ]
}
