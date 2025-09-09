# Inventory Stock Manager - Process Sales & Zero Stock Module

def process_sale(inventory, sku, qty_sold):
    """
    Decrease stock of specific SKU based on sales.

    Args:
        inventory (list of tuples): [(SKU, quantity), ...]
        sku (int): SKU identifier to process sale
        qty_sold (int): Quantity sold

    Returns:
        updated_inventory (list of tuples)
    """
    updated_inventory = []
    sku_found = False

    for item in inventory:
        current_sku, current_qty = item
        if current_sku == sku:
            sku_found = True
            if current_qty >= qty_sold:
                updated_inventory.append((current_sku, current_qty - qty_sold))
                print(f"Sale processed: {qty_sold} units of SKU {sku}.")
            else:
                updated_inventory.append((current_sku, current_qty))
                print(f"Insufficient stock for SKU {sku}. Available: {current_qty}")
        else:
            updated_inventory.append(item)

    if not sku_found:
        print(f"SKU {sku} not found in inventory.")

    return updated_inventory


def identify_zero_stock(inventory):
    """
    Identify all SKUs with zero stock.

    Args:
        inventory (list of tuples): [(SKU, quantity), ...]

    Returns:
        zero_stock_list (list of int): SKUs with zero quantity
    """
    zero_stock_list = [sku for sku, qty in inventory if qty == 0]
    if zero_stock_list:
        print(f"Zero stock SKUs: {zero_stock_list}")
    else:
        print("No zero stock items found.")
    return zero_stock_list


# --- Example Usage ---
if __name__ == "__main__":
    inventory = [(101, 50), (102, 20), (103, 0)]

    # Process sales
    inventory = process_sale(inventory, 101, 30)   # Normal sale
    inventory = process_sale(inventory, 102, 25)   # Insufficient stock
    inventory = process_sale(inventory, 104, 10)   # SKU not found

    # Identify zero stock
    zero_stock_items = identify_zero_stock(inventory)

    print("Updated Inventory:", inventory)


# ------------------ TEST CASES ------------------
def run_tests():
    print("\nRunning Test Cases...\n")

    # TC1 – Normal Sale
    inventory = [(101, 50)]
    result = process_sale(inventory, 101, 30)
    print("Expected: [(101, 20)] | Got:", result, "\n")

    # TC2 – Insufficient Stock
    inventory = [(102, 20)]
    result = process_sale(inventory, 102, 25)
    print("Expected: [(102, 20)] | Got:", result, "\n")

    # TC3 – SKU Not Found
    inventory = [(101, 50)]
    result = process_sale(inventory, 104, 10)
    print("Expected: [(101, 50)] | Got:", result, "\n")

    # TC4 – Zero Stock Detection
    inventory = [(101, 0), (102, 5), (103, 0)]
    result = identify_zero_stock(inventory)
    print("Expected: [101, 103] | Got:", result, "\n")

    # TC5 – No Zero Stock
    inventory = [(101, 10), (102, 5)]
    result = identify_zero_stock(inventory)
    print("Expected: [] | Got:", result, "\n")

    # TC6 – Sale Reducing to Zero
    inventory = [(101, 10)]
    result = process_sale(inventory, 101, 10)
    print("Expected: [(101, 0)] | Got:", result, "\n")


# Run all tests
run_tests()