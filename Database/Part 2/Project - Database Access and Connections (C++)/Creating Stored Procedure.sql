SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE find_customer (customer_id IN NUMBER, found OUT NUMBER) AS
    v_cname customers.cname%TYPE;
BEGIN
    SELECT cname INTO v_cname FROM customers
    WHERE cust_no = customer_id;
    found := 1;
EXCEPTION
    WHEN no_data_found THEN
        found := 0;
END find_customer;
/


CREATE OR REPLACE PROCEDURE find_product (product_id IN NUMBER, price OUT products.prod_sell%TYPE) AS
BEGIN
    SELECT prod_sell INTO price FROM products
    WHERE prod_no = product_id;
EXCEPTION
    WHEN no_data_found THEN
        price := 0;
END find_product;
/


CREATE OR REPLACE PROCEDURE add_order (customer_id IN NUMBER, new_order_id OUT NUMBER) AS
BEGIN
    SELECT MAX(order_no) + 1 INTO new_order_id FROM orders;
    
    INSERT INTO orders (order_no, rep_no, cust_no, order_dt, status)
    VALUES (new_order_id, 36, customer_id, sysdate, 'C');
    
exception
    WHEN others THEN
dbms_output.put_line('You have an Error!');
END add_order;
/


CREATE OR REPLACE PROCEDURE add_orderline (
    orderid     IN   orderlines.order_no%TYPE,
    itemid      IN   orderlines.line_no%TYPE,
    productid   IN   orderlines.prod_no%TYPE,
    quantity    IN   orderlines.qty%TYPE,
    price       IN   orderlines.price%TYPE
) AS
BEGIN

    INSERT INTO orderlines (order_no, line_no, prod_no, price, qty)
    VALUES (orderid, itemid, productid, price, quantity);

EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('You have an Error!');
END add_orderline;
/

