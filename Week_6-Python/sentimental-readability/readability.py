from cs50 import get_string


def get_gradelevel(S, L):
    gradelevel = 0.0588 * L - 0.296 * S - 15.8
    if gradelevel < 1:
        print("Before Grade 1")
    elif gradelevel > 1 and gradelevel < 16:
        print(f"Grade {round(gradelevel)}")
    else:
        print("Grade 16+")


def get_SL(text):
    L = 0
    S = 0
    for wordcount, word in enumerate(text.split(), start=1):
        for letter in word:
            if letter in {".", "!", "?"}:
                S += 1
            elif letter.isalpha():
                L += 1

    S = (100 / wordcount) * S
    L = (100 / wordcount) * L
    return S, L


def main():
    text = get_string("Text to test: ")
    S, L = get_SL(text)
    get_gradelevel(S, L)

    
main()
