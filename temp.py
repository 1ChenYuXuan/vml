
path: str = 'a.vmlc'

def read(path: str) -> str:
    try:
        with open(path, 'r') as file:
            return file.read()
    except FileNotFoundError:
        raise FileNotFoundError(f"File not found: {path}")


def write(path: str, content: bytes) -> None:
    try:
        with open(path, 'ab') as file:
            file.write(content)
    except IOError as e:
        raise IOError(f"Error writing to file: {e}")


def main() -> None:
    with open(path, 'w') as file:
        file.write('This is vml\'s.')
    byteslist: list[int] = [
        6, 0, 12, # MOV function.
        1, # 1 byte.
        128, # a data.
        0, 
        0 # location
    ]
    for byte in byteslist:
        write(path, bytes(chr(byte), 'utf-8'))

if __name__ == '__main__':
    main()

