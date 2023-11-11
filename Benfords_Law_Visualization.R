# Load necessary library
library(ggplot2)

# Benford's Law function to calculate expected proportions
benford <- function(d) {
  if(d == 0) return(0)
  return(log10(1 + 1/d))
}

# Generate data for the first two digits
digits <- 10:99
benford_values <- sapply(digits, benford)

# Simulate actual data - this is just a placeholder for real data
set.seed(123) # for reproducibility
actual_data <- rpois(90, lambda = 30)
actual_data <- actual_data / sum(actual_data)

# Create a data frame for plotting
df <- data.frame(
  FirstTwoDigits = digits,
  Actual = actual_data,
  BenfordLaw = benford_values
)

# Plot the data
ggplot(data = df, aes(x = FirstTwoDigits)) +
  geom_bar(aes(y = Actual), stat = "identity", fill = "grey") +
  geom_line(aes(y = BenfordLaw), color = "blue", linewidth = 1) +
  labs(title = "Benford's Law Visualization",
       x = "First-Two Digits",
       y = "Proportion") +
  theme_minimal()

