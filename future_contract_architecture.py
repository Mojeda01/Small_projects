from datetime import datetime, timedelta
from hashlib import blake2b
import json

# Generate future timepoint
def future_time(time_delta_fut):
    dt = datetime.now()
    td = timedelta(days=time_delta_fut)
    future_date = dt + td
    future_date_d1 = future_date.strftime("%d/%m/%Y %H:%M:%S")
    return future_date_d1

# Futures Contract ID generator
def contract_id_gen(string_keyword):
    bytes_keyword = bytes(string_keyword, encoding="utf8")
    blake2b_key = blake2b(key=bytes_keyword, digest_size=20).hexdigest()
    return blake2b_key

# Generate file name for the contract
def file_name_gen(string_keyword):
    bytes_keyword_file = bytes(string_keyword, encoding="utf8")
    blake2b_key = blake2b(key=bytes_keyword_file, digest_size=20).hexdigest()
    return blake2b_key

# Function for generating the JSON object
def future_JSON_format(format_contract, file_name):
    final_file_name = file_name + ".json"
    json_object = json.dumps(format_contract, indent=7)
    with open(final_file_name, "w") as outfile:
        outfile.write(json_object)
