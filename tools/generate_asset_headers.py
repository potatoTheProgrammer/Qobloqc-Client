from pathlib import Path

main_path = Path(__file__).parent.parent
textures_path = main_path/"assets"/"textures"

generated_headers_path = main_path/"include"/"generated"
generated_textures_path = generated_headers_path/"textures"

generated_headers_path.mkdir(parents = True, exist_ok = True)
generated_textures_path.mkdir(exist_ok = True)

for texture_path in textures_path.glob("*.png"):
    variable_name = texture_path.stem.replace("-", "_").replace(" ", "_")
    header_path = generated_textures_path/(variable_name + ".hpp")
    
    with open(texture_path, "rb") as texture_file:
        texture_bytes = texture_file.read()
    
    with open(header_path, "w") as header_file:
        header_file.write("/*  " + header_path.name + "\n\nA texture header auto-generated from " + texture_path.name + ".\n\n*/\n\n")
        header_file.write("const unsigned char " + variable_name + "[] = {\n    ")
        header_file.write(", ".join([f"0x{byte:02x}" for byte in texture_bytes]))
        header_file.write("\n};")
    
    print(header_path.name)

input("Done! Press Enter to close.")