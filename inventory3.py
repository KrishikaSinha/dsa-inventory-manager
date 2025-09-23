# Browser Simulation using Stack

history = []          # Stack for visited pages
forward_stack = []    # Stack for forward navigation


def visit_page(page):
    history.append(page)   # Push onto history
    forward_stack.clear()  # Clear forward stack on new visit
    print(f"Visited: {page}")


def go_back():
    if not history:
        print("No pages in history.")
        return
    last_page = history.pop()   # Remove current page
    forward_stack.append(last_page)
    if history:
        print(f"Going back... Current page: {history[-1]}")
    else:
        print("No pages left in history.")


def go_forward():
    if not forward_stack:
        print("No forward pages available.")
        return
    page = forward_stack.pop()
    history.append(page)
    print(f"Forward to: {page}")


def show_history():
    if not history:
        print("History is empty.")
    else:
        print("History:", " -> ".join(history))


# ---------------- Menu ----------------
while True:
    print("\n1. Visit Page")
    print("2. Back")
    print("3. Forward")
    print("4. Show History")
    print("5. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        page = input("Enter page name: ")
        visit_page(page)
    elif choice == "2":
        go_back()
    elif choice == "3":
        go_forward()
    elif choice == "4":
        show_history()
    elif choice == "5":
        print("Exiting browser simulation.")
        break
    else:
        print("Invalid choice.")
