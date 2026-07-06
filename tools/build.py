import shutil
import subprocess
from pathlib import Path

def build():
    if shutil.which("cmake") is None:
        print("CMake could not be found in your system's PATH.\nDownload it here: https://cmake.org/download/\n")
        return
    
    if not (Path(__file__).parent.parent/"build").is_dir():
        generator = input("Choose the CMake generator (Leave blank for \"MinGW Makefiles\"): ")
        if not generator:
            generator = "MinGW Makefiles"
        
        configure_command = [
            "cmake",
            "-G", generator,
            "-S", "..",
            "-B", "../build",
        ]
        
        configure_result = subprocess.run(configure_command, capture_output = True, text = True)
        print(configure_result.stdout)
    
    build_command = [
        "cmake",
        "--build", "../build",
    ]
    
    build_result = subprocess.run(build_command, capture_output = True, text = True)
    print(build_result.stdout)

build()
input("Done! Press Enter to close.")