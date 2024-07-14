CREATE TABLE S2020115630.PERSON (
    PersonID VARCHAR2(100) PRIMARY KEY,
    PersonName VARCHAR2(100) NOT NULL,
    DateOfBirth DATE,
    FatherName VARCHAR2(100),
    MotherName VARCHAR2(100),
    Gender VARCHAR2(6) NOT NULL CHECK (Gender IN ('Male', 'Female')),

    CONSTRAINT FK_Father FOREIGN KEY (FatherName)
        REFERENCES S2020115630.PERSON (PersonID) ON DELETE SET NULL,

    CONSTRAINT FK_Mother FOREIGN KEY (MotherName)
        REFERENCES S2020115630.PERSON (PersonID) ON DELETE SET NULL
);

  CREATE TABLE "S2020115630"."COMPANY" 
   (
    CompanyID VARCHAR2(100 ) PRIMARY Key , 
	CompanyName VARCHAR2(100 ) NOT NULL, 
	CompanyCapital NUMBER(10,2), 
	
   );

Create table Investment(
    CompanyID varchar(100),
    PersonID varchar(100),
    PersonShare number(3,2),
    
    Constraint fk_personID Foreign Key (PersonID) References Person(PersonID) ,
    Constraint fk_CompanyID Foreign Key (CompanyID) References Company(CompanyID)
);








INSERT INTO "S2020115630"."PERSON" 
("PERSONID", "PERSONNAME", "DATEOFBIRTH", "FATHERNAME", "MOTHERNAME", "GENDER")
VALUES 
('P001', 'Rahul Khan', TO_DATE('1990-01-01', 'YYYY-MM-DD'), NULL, NULL, 'Male');

INSERT INTO "S2020115630"."PERSON" 
("PERSONID", "PERSONNAME", "DATEOFBIRTH", "FATHERNAME", "MOTHERNAME", "GENDER")
VALUES 
('P001', 'Reshma Khan', TO_DATE('1990-01-01', 'YYYY-MM-DD'), NULL, NULL, 'Female');


INSERT INTO "S2020115630"."PERSON" 
("PERSONID", "PERSONNAME", "DATEOFBIRTH", "FATHERNAME", "MOTHERNAME", "GENDER")
VALUES 
('P3', 'Ratul Khan', TO_DATE('1990-01-01', 'YYYY-MM-DD'), NULL, NULL, 'Male');

INSERT INTO "S2020115630"."PERSON" 
("PERSONID", "PERSONNAME", "DATEOFBIRTH", "FATHERNAME", "MOTHERNAME", "GENDER")
VALUES 
('P4', 'Rohima Khan', TO_DATE('1990-01-01', 'YYYY-MM-DD'), NULL, NULL, 'Female');


INSERT INTO "S2020115630"."PERSON" 
("PERSONID", "PERSONNAME", "DATEOFBIRTH", "FATHERNAME", "MOTHERNAME", "GENDER")
VALUES 
('P5', 'Rabbi Khan', TO_DATE('2010-01-01', 'YYYY-MM-DD'), 'P001', 'P002', 'Male');

INSERT INTO "S2020115630"."PERSON" 
("PERSONID", "PERSONNAME", "DATEOFBIRTH", "FATHERNAME", "MOTHERNAME", "GENDER")
VALUES 
('P6', 'Ruhi Khan', TO_DATE('2010-01-01', 'YYYY-MM-DD'), 'P001', 'P002', 'Female');

INSERT INTO "S2020115630"."PERSON" 
("PERSONID", "PERSONNAME", "DATEOFBIRTH", "FATHERNAME", "MOTHERNAME", "GENDER")
VALUES 
('P7', 'Ranga Khan', TO_DATE('2010-01-01', 'YYYY-MM-DD'), 'P3', 'P4', 'Male');

INSERT INTO "S2020115630"."PERSON" 
("PERSONID", "PERSONNAME", "DATEOFBIRTH", "FATHERNAME", "MOTHERNAME", "GENDER")
VALUES 
('P8', 'Rani Khan', TO_DATE('2010-01-01', 'YYYY-MM-DD'), 'P3', 'P4', 'Female');









INSERT INTO "S2020115630"."COMPANY" 
("COMPANYID", "COMPANYNAME", "COMPANYCAPITAL")
VALUES 
('C1', 'Tech Solutions', 500000.00);

INSERT INTO "S2020115630"."COMPANY" 
("COMPANYID", "COMPANYNAME", "COMPANYCAPITAL")
VALUES 
('C2', 'ORACLE', 500040.00);

INSERT INTO "S2020115630"."COMPANY" 
("COMPANYID", "COMPANYNAME", "COMPANYCAPITAL")
VALUES 
('C3', 'MICROSOFT', 400000.00);




INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C1', 'P001', 2.50);


INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C1', 'P002', 5.50);

INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C1', 'P3', 5.50);

INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C1', 'P4', 4.50);


INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C2', 'P001', 2.50);


INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C2', 'P002', 5.50);

INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C2', 'P3', 5.50);

INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C2', 'P4', 4.50);

INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C2', 'P5', 2.50);


INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C2', 'P6', 5.50);

INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C2', 'P7', 5.50);

INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C2', 'P8', 4.50);




INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C3', 'P001', 2.50);


INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C3', 'P002', 5.50);

INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C3', 'P3', 5.50);

INSERT INTO Investment
(CompanyID, PersonID, PersonShare)
VALUES
('C3', 'P7', 4.50);




