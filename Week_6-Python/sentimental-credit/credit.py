from cs50 import get_string


def get_array(cardnumber):
    numbers = []
    # convert string into integers and put into a list
    for number in cardnumber:
        numbers.append(int(number))

    return numbers


def validate(numbers):
    numsum = []

    # get the sum of every other number starting from second to last number
    for number in range((len(numbers) - 2), -1, -2):
        numsum.append(numbers[number] * 2)

    #convert all sums into a string so that we can separate any double-digit numbers
    numsumstr = ""
    for num in numsum:
        numsumstr += str(num)

    # add together all the digits
    strsum = 0
    for string in numsumstr:
        strsum += int(string)

    # get the sum of the unchecked numbers from the first step and the strsum
    for uncheckednum in range((len(numbers) - 1), -1, -2):
        strsum += numbers[uncheckednum]

    # turn the final sum into a string so that the second digit can be checked
    finalsum = str(strsum)

    # get the first two numbers of the card as a string
    checkftn = str((numbers[0])) + str((numbers[1]))

    # check for card type
    if finalsum[1] == "0" and (len(numbers) == 13 or len(numbers) == 16) and numbers[0] == 4:
        print("VISA")
    elif finalsum[1] == "0" and len(numbers) == 16 and int(checkftn) >= 51 and int(checkftn) <= 55:
        print("MASTERCARD")
    elif finalsum[1] == "0" and len(numbers) == 15 and (int(checkftn) == 34 or int(checkftn) == 37):
        print("AMEX")
    else:
        print("INVALID")


def main():
    cardnumber = get_string("Input card number: ")
    numbers = get_array(cardnumber)
    strsum = validate(numbers)


main()
