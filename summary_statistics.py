import matplotlib


# Calculate the average
def calculate_average(numbers):
    total = sum(numbers)
    count = len(numbers)

    if count == 0:
        return 0 # Return 0 if the list is empty to avoid division by zero

    average = total / count
    return average


# sum = 1 + 2 + 3 +...+ n
def calculate_sum(n):
    tota = 0
    for i in range(1, n + 1):
        total += i
    return total


def calculate_mean(data):
    n = len(data)
    total = sum(data)
    mean = total / n
    return mean
    
def calculate_variance(data):
    mean = calculate_mean(data)
    squared_diff_sum = sum((x-mean) ** 2 for x in data)
    variance = squared_diff_sum / (len(data) - 1)
    return variance

def calculate_standard_deviation(data):
    variance = calculate_variance(data)
    standard_deviation = variance ** 0.5
    return standard_deviation

def calculate_covariance(data_x, data_y):
    mean_x = calculate_mean(data_x)
    mean_y = calculate_mean(data_y)

    covariance = sum((x - mean_x) * (y - mean_y) for x, y in zip(data_x, data_y)) / (len(data_x) - 1)
    return covariance

def calculate_correlation(data_x, data_y):
    covariance = calculate_covariance(data_x, data_y)
    standard_deviation_x = (calculate_variance(data_x)) ** 0.5
    standard_deviation_y = (calculate_variance(data_y)) ** 0.5
    correlation = covariance / (standard_deviation_x * standard_deviation_y)
    return correlation


# Example usage
data_x = [12, 15, 18, 20, 25]
data_y = [30, 35, 40, 45, 50]
covariance_result = calculate_covariance(data_x, data_y)
correlation_result = calculate_correlation(data_x, data_y)

print("Covariance:", covariance_result)
print("Correlation:", correlation_result)
