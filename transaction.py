import fnmatch
import os

class Edit_String:

    x = fnmatch.filter(os.listdir('.'), 'ww*.txt')
    x_convert = str(x)

    def remove_string_element():
        remove_z = Edit_String.x_convert.replace(Edit_String.x_convert[0] + Edit_String.x_convert[1], '')
        remove_o = remove_z.replace(Edit_String.x_convert[24] + Edit_String.x_convert[25], '')
        return remove_o
    
    def open_wallet_file():
        wallet_file = open(Edit_String.remove_string_element(), "r")
        return wallet_file.read()

print(Edit_String.remove_string_element())
