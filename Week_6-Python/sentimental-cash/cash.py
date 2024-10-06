from cs50 import get_float


def get_change(prompt):
    while True:
        change = get_float(prompt)
        if change > 0:
            change = change * 100
            return change


def sort_change(change):
    coins = {
        "quarter": 25,
        "dime": 10,
        "nickel": 5,
        "penny": 1,
    }

    total = 0
    while change > 0:
        if change >= coins["quarter"]:
            change -= coins["quarter"]
            total += 1
        elif change >= coins["dime"]:
            change -= coins["dime"]
            total += 1
        elif change >= coins["nickel"]:
            change -= coins["nickel"]
            total += 1
        else:
            change -= coins["penny"]
            total += 1

    return total


def main():
    change = get_change("What is the change owed? ")

    total = sort_change(change)

    print(total)


main()
