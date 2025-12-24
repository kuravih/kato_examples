threads_dep = dependency('threads')

conf = configure_file(
    input: 'path.h.in',
    output: 'path.h',
    configuration: {
        'SRC_ROOT': meson.project_source_root()
    }
)

lib_include = include_directories('../lib')

executable(
    '03_truetype',
    ['main.cpp', conf],
    include_directories : lib_include,
    dependencies : threads_dep,
    install : false
)