flags = [
    '-Wall',
    '-Wextra',
    '-Werror',
    '-std=c++17',  # Or whatever C++ standard you are using
    '-x', 'c++',
    '-I', '/usr/local/include/boost',  # Add your Boost include path here
    '-I', '.',  # If you have project-specific includes
    # Other include paths or flags as needed
]

def FlagsForFile(filename, **kwargs):
    return {
        'flags': flags,
        'do_cache': True
    }
