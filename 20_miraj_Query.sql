
-- query for getting information about perrson whose date of birth is after 2000
Select * from Person where DateOfBirth> TO_DATE('2000-01-01', 'YYYY-MM-DD');

--getting age of each person 
Select personName,  TRUNC(MONTHS_BETWEEN(SYSDATE, DateOfBirth) / 12) as Age from Person;

--person with father and mother is null
SELECT personName FROM Person WHERE fatherName IS NULL AND motherName IS NULL;

--person who have parents 
SELECT personName FROM Person WHERE fatherName IS NOT NULL AND motherName IS NOT NULL;

--each person share in each company 
SELECT SUM(PersonShare) AS totalShare, CompanyID FROM Investment group by CompanyID ;




-- B.1 number of investor in each company 
SELECT Count(PersonShare) AS totalShare, CompanyID FROM Investment group by CompanyID ;



-- createing a procedure for calculation investment amount in each company by each person 
CREATE OR REPLACE FUNCTION calculate_investment
    (p_person_share IN NUMBER,
     p_company_capital IN NUMBER)
RETURN NUMBER
IS
    total_value NUMBER;
BEGIN
    -- Calculate total investment value
    total_value := (p_person_share / 100) * p_company_capital;
    RETURN total_value;
END;

-- getting total amount of investment by each person family 
Select Person.PersonID,
    sum( calculate_investment(Investment.PersonShare, Company.CompanyCapital) ) as total  from
    Investment join Person on
    Person.PersonID = Investment.PersonID or
    Person.fathername = Investment.PersonID or
    Person.PersonID = Investment.PersonID
    join Company on Company.CompanyID = Investment.CompanyID
    group by Person.PersonID ;
