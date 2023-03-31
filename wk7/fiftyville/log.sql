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

SELECT account_number, atm_location, transaction_type, amount FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

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


-- Raymond
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.

SELECT caller, receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28;

/*
+----------------+----------------+
|     caller     |    receiver    |
+----------------+----------------+
| (336) 555-0077 | (098) 555-1164 |
| (918) 555-5327 | (060) 555-2489 |
| (491) 555-2505 | (478) 555-1565 |
| (996) 555-8899 | (059) 555-4698 |
| (704) 555-5790 | (772) 555-5770 |
| (984) 555-5921 | (618) 555-9856 |
| (579) 555-5030 | (971) 555-6468 |
| (233) 555-0473 | (831) 555-0973 |
| (293) 555-1469 | (749) 555-4874 |
| (450) 555-8297 | (771) 555-7880 |
| (130) 555-0289 | (996) 555-8899 |
| (209) 555-7806 | (693) 555-7986 |
| (918) 555-2946 | (006) 555-0505 |
| (499) 555-9472 | (892) 555-8872 |
| (669) 555-6918 | (914) 555-5994 |
| (547) 555-8781 | (398) 555-1013 |
| (544) 555-8087 | (389) 555-5198 |
| (666) 555-5774 | (125) 555-8030 |
| (047) 555-0577 | (059) 555-4698 |
| (301) 555-4174 | (711) 555-3007 |
| (801) 555-9266 | (984) 555-5921 |
| (971) 555-6468 | (267) 555-2761 |
| (367) 555-5533 | (375) 555-8161 |
| (609) 555-5876 | (389) 555-5198 |
| (357) 555-0246 | (502) 555-6712 |
| (367) 555-5533 | (344) 555-9601 |
| (394) 555-3247 | (035) 555-2997 |
| (839) 555-1757 | (487) 555-5865 |
| (770) 555-1196 | (324) 555-0416 |
| (636) 555-4198 | (670) 555-8598 |
| (068) 555-0183 | (770) 555-1861 |
| (711) 555-3007 | (113) 555-7544 |
| (060) 555-2489 | (204) 555-4136 |
| (704) 555-2131 | (891) 555-5672 |
| (367) 555-5533 | (022) 555-4052 |
| (873) 555-3868 | (047) 555-0577 |
| (867) 555-9103 | (068) 555-0183 |
| (608) 555-9302 | (725) 555-3243 |
| (901) 555-8732 | (491) 555-2505 |
| (478) 555-1565 | (717) 555-1342 |
| (499) 555-9472 | (717) 555-1342 |
| (695) 555-0348 | (338) 555-6650 |
| (696) 555-9195 | (258) 555-5627 |
| (286) 555-6063 | (676) 555-6554 |
| (770) 555-1861 | (725) 555-3243 |
| (711) 555-3007 | (147) 555-6818 |
| (725) 555-4692 | (821) 555-5262 |
| (324) 555-0416 | (452) 555-8550 |
| (234) 555-1294 | (772) 555-5770 |
| (669) 555-6918 | (971) 555-6468 |
| (031) 555-6622 | (910) 555-3251 |
| (342) 555-9260 | (219) 555-0139 |
| (342) 555-9260 | (487) 555-5865 |
| (801) 555-9266 | (608) 555-9302 |
| (398) 555-1013 | (329) 555-5870 |
| (016) 555-9166 | (336) 555-0077 |
| (594) 555-2863 | (491) 555-2505 |
| (122) 555-4581 | (831) 555-0973 |
| (914) 555-5994 | (973) 555-3809 |
| (258) 555-5627 | (695) 555-0348 |
| (751) 555-6567 | (594) 555-6254 |
| (771) 555-7880 | (711) 555-3007 |
| (219) 555-0139 | (867) 555-9103 |
| (676) 555-6554 | (328) 555-9658 |
| (749) 555-4874 | (492) 555-5484 |
| (328) 555-9658 | (775) 555-7584 |
| (219) 555-0139 | (910) 555-3251 |
| (380) 555-4380 | (680) 555-4935 |
| (826) 555-1652 | (066) 555-9701 |
| (594) 555-6254 | (123) 555-5144 |
| (338) 555-6650 | (704) 555-2131 |
| (971) 555-6468 | (258) 555-5627 |
| (730) 555-5115 | (343) 555-0167 |
| (286) 555-6063 | (310) 555-8568 |
| (367) 555-5533 | (704) 555-5790 |
| (041) 555-4011 | (609) 555-5876 |
| (478) 555-1565 | (031) 555-6622 |
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

SELECT DISTINCT 
FROM people p1
INNER JOIN stars s1 ON s1.person_id = p1.id
INNER JOIN stars s2 ON s2.movie_id = s1.movie_id
INNER JOIN people p2 ON p2.id = s2.person_id
WHERE p2.name = 'Kevin Bacon' AND p1.name != 'Kevin Bacon';
