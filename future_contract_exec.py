import future_contract_architecture

# Variable for future_contract_architecture
futures = future_contract_architecture

# Setting a default maturity for 5 days
maturity = futures.future_time(5)
string_maturity = str(maturity)

# Setting a default purchase price (for now)
purchase_price = 100
string_purchase_price = str(purchase_price)

# Setting contract ID
sample_keyword = "test_keyword"
contract_id = futures.contract_id_gen(sample_keyword)
string_contract_id = str(contract_id)
 
# Generate file name
sample_file_keyword = "test_keyword"
gen_file_name = futures.file_name_gen(sample_file_keyword)
string_sample_file_keyword = str(gen_file_name)

# The JSON format that is going to get used for the contract format
contract_content= {
    "Contract_type" : "FUTURE",
    "Maturity" : string_maturity,
    "Purchase_price" : string_purchase_price,
    "Contract_id" : string_contract_id,
    "Purchaser" : "sample_name_for_purchaser",        
    "Seller" : "sample_name_for_seller",
    "file_name" : string_sample_file_keyword
}

# Generate the JSON file
JSON_file = futures.future_JSON_format(contract_content, string_sample_file_keyword)