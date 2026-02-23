
# As C++

def lexer(codes) -> list[list[str]]:
    tsplit_lines: list[str] = code.split('\n')
    split_lines: list[str] = []
    for code in tspilt_codes:
        code = code.strip()
        if code:
            split_lines.append(code)
    
    split_tokens: list[list[str]] = []
    for spilt_code in split_codes:
        tokens: list[str] = []
        for token in split_code.split(): # libs/string.hop::ssar
            if token:
                tokens.append(token)
        split_tokens.append(tokens)


