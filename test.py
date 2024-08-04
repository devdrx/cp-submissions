def main():
    # Open a file in write mode
    with open("output.txt", "w") as outputFile:
        # Loop through the specified range and write to the file
        for i in range(100, 4500):
            for j in range(1, 8):
                outputFile.write(f"{i} {j}\n")

    print("Output successfully written to output.txt")

if __name__ == "__main__":
    main()