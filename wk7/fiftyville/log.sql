-- Keep a log of any SQL queries you execute as you solve the mystery.

.schema

CREATE TABLE crime_scene_reports (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    street TEXT,
    description TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE interviews (
    id INTEGER,
    name TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    transcript TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE atm_transactions (
    id INTEGER,
    account_number INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    atm_location TEXT,
    transaction_type TEXT,
    amount INTEGER,
    PRIMARY KEY(id)
);
CREATE TABLE bank_accounts (
    account_number INTEGER,
    person_id INTEGER,
    creation_year INTEGER,
    FOREIGN KEY(person_id) REFERENCES people(id)
);
CREATE TABLE airports (
    id INTEGER,
    abbreviation TEXT,
    full_name TEXT,
    city TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE flights (
    id INTEGER,
    origin_airport_id INTEGER,
    destination_airport_id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY(origin_airport_id) REFERENCES airports(id),
    FOREIGN KEY(destination_airport_id) REFERENCES airports(id)
);
CREATE TABLE passengers (
    flight_id INTEGER,
    passport_number INTEGER,
    seat TEXT,
    FOREIGN KEY(flight_id) REFERENCES flights(id)
);
CREATE TABLE phone_calls (
    id INTEGER,
    caller TEXT,
    receiver TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    duration INTEGER,
    PRIMARY KEY(id)
);
CREATE TABLE people (
    id INTEGER,
    name TEXT,
    phone_number TEXT,
    passport_number INTEGER,
    license_plate TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE bakery_security_logs (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    activity TEXT,
    license_plate TEXT,
    PRIMARY KEY(id)
);


SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

-- Result:
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time –
-- each of their interview transcripts mentions the bakery.

SELECT * FROM interviews WHERE transcript LIKE '%bakery%' AND month = 7;

-- Ruth
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

SELECT hour, minute, activity, license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 5 AND 25 AND activity = 'exit';

/*
+------+--------+----------+---------------+
| hour | minute | activity | license_plate |
+------+--------+----------+---------------+
| 10   | 16     | exit     | 5P2BI95       |
| 10   | 18     | exit     | 94KL13X       |
| 10   | 18     | exit     | 6P58WS2       |
| 10   | 19     | exit     | 4328GD8       |
| 10   | 20     | exit     | G412CB7       |
| 10   | 21     | exit     | L93JTIZ       |
| 10   | 23     | exit     | 322W7JE       |
| 10   | 23     | exit     | 0NTHK55       |
+------+--------+----------+---------------+
*/

-- Eugene
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
-- I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw');

/*
+----------------+----------------+------------------+--------+
| account_number |  atm_location  | transaction_type | amount |
+----------------+----------------+------------------+--------+
| 28500762       | Leggett Street | withdraw         | 48     |
| 28296815       | Leggett Street | withdraw         | 20     |
| 76054385       | Leggett Street | withdraw         | 60     |
| 49610011       | Leggett Street | withdraw         | 50     |
| 16153065       | Leggett Street | withdraw         | 80     |
| 25506511       | Leggett Street | withdraw         | 20     |
| 81061156       | Leggett Street | withdraw         | 30     |
| 26013199       | Leggett Street | withdraw         | 35     |
+----------------+----------------+------------------+--------+
*/

SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw');

/*
+-----------+
| person_id |
+-----------+
| 686048    |
| 514354    |
| 458378    |
| 395717    |
| 396669    |
| 467400    |
| 449774    |
| 438727    |
+-----------+
*/


-- Raymond
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.

SELECT caller, receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60;

/*
+----------------+----------------+
|     caller     |    receiver    |
+----------------+----------------+
| (130) 555-0289 | (996) 555-8899 |
| (499) 555-9472 | (892) 555-8872 |
| (367) 555-5533 | (375) 555-8161 |
| (609) 555-5876 | (389) 555-5198 |
| (499) 555-9472 | (717) 555-1342 |
| (286) 555-6063 | (676) 555-6554 |
| (770) 555-1861 | (725) 555-3243 |
| (031) 555-6622 | (910) 555-3251 |
| (826) 555-1652 | (066) 555-9701 |
| (338) 555-6650 | (704) 555-2131 |
+----------------+----------------+
*/

SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE month = 7 AND day = 29 AND hour < 12);

/*
+-----------------+
| passport_number |
+-----------------+
| 7214083635      |
| 1695452385      |
| 5773159633      |
| 1540955065      |
| 8294398571      |
| 1988161715      |
| 9878712108      |
| 8496433585      |
| 7597790505      |
| 6128131458      |
| 6264773605      |
| 3642612721      |
| 4356447308      |
| 7441135547      |
+-----------------+
*/

SELECT DISTINCT p1.name
FROM people p1
INNER JOIN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 5 AND 25 AND activity = 'exit') t1 ON p1.license_plate = t1.license_plate
INNER JOIN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw')) t2 ON p1.id = t2.person_id
INNER JOIN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60) t3 ON t3.caller = p1.phone_number
INNER JOIN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE month = 7 AND day = 29 AND hour < 12)) t4 ON t4.passport_number = p1.passport_number;

/*
+-------+
| name  |
+-------+
| Bruce |
+-------+
*/

SELECT receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60 AND caller IN (SELECT phone_number FROM people WHERE name = 'Bruce');

/*
+----------------+
|    receiver    |
+----------------+
| (375) 555-8161 |
+----------------+
*/

SELECT name FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60 AND caller IN (SELECT phone_number FROM people WHERE name = 'Bruce'));

/*
+-------+
| name  |
+-------+
| Robin |
+-------+
*/

SELECT destination_airport_id IN (SELECT phone_number FROM people WHERE name = 'Bruce');