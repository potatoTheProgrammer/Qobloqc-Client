from urllib.request import urlretrieve
from pathlib import Path

third_party_headers_path = Path(__file__).parent.parent/"include"/"third_party"

print("Downloading stb_image...")
urlretrieve("https://github.com/nothings/stb/raw/refs/heads/master/stb_image.h", third_party_headers_path/"stb_image.h")
print("Downloading miniaudio...")
urlretrieve("https://raw.githubusercontent.com/mackron/miniaudio/master/miniaudio.h", third_party_headers_path/"miniaudio.h")

input("Done! Press Enter to close.")