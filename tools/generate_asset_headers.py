from pathlib import Path

main_path = Path(__file__).parent.parent
textures_path = main_path/"assets"/"textures"

generated_headers_path = main_path/"include"/"generated"
generated_source_path = main_path/"src"/"generated"

generated_headers_path.mkdir(parents = True, exist_ok = True)
generated_source_path.mkdir(parents = True, exist_ok = True)

with open(generated_source_path/"builtin_textures.cpp", "w") as builtin_textures_file:
    with open(generated_headers_path/"builtin_textures.hpp", "w") as texture_header_file:
        texture_header_file.write("/*  builtin_textures.hpp\n\nThis header file declares all built-in textures.\n\n*/\n")
        for texture_path in textures_path.glob("*.png"):
            variable_name = texture_path.stem.replace("-", "_").replace(" ", "_")
            texture_header_file.write("\nextern const unsigned char " + variable_name + "[];")
    builtin_textures_file.write("/*  builtin_textures.cpp\n\nThis source file defines all built-in textures.\n\n*/\n\n#include \"generated/builtin_textures.hpp\"")
    for texture_path in textures_path.glob("*.png"):
        variable_name = texture_path.stem.replace("-", "_").replace(" ", "_")
        builtin_textures_file.write("\n\nconst unsigned char " + variable_name + "[] = {\n    ")
        with open(texture_path, "rb") as texture_file:
            texture_bytes = texture_file.read()
            builtin_textures_file.write(", ".join([f"0x{byte:02x}" for byte in texture_bytes]))
        builtin_textures_file.write("\n};")

input("Done! Press Enter to close.")