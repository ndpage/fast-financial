flags = [
    '-Wall',
    '-Wextra',
    '-Werror',
    '-std=c++20', 
    '-x', 'c++',
    '-I', '/usr/include', 
    '-I', '/usr/local/include', 
    '-I', '/usr/local/include/boost',  # Add your Boost include path here
    '-I', '.',  # If you have project-specific includes
    # Other include paths or flags as needed
]

def FlagsForFile(filename, **kwargs):
    return {
        'flags': flags,
        'do_cache': True
    }
