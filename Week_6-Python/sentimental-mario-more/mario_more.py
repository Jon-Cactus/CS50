def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Not an integer")


def main():
    while True:
        height = get_int("Pyramid height: ")
        if height > 0 and height < 9:
            break
        else:
            print("Height must be between 1 and 8")

    space = height - 1
    for i in range(height):

        # prints first spaces
        print(" " * space, end="")

        #prints left side of pyramid
        print("#" * (i + 1), end="")

        #prints space between pyramids
        print("  ", end="")

        #prints right side pyramid
        print("#" * (i + 1), end="")

        space -= 1
        print()


main()
