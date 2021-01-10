from tinymlgen import port

model = "/Users/raybechard/desktop/Door-Detection/convert_cc_h.py"
c_code = port(model, pretty_print=True)
print(c_code)
