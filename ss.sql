Select Person.PersonID,
    sum(Investment.PersonShare ) as total   from
    Investment join Person on
    Person.PersonID = Investment.PersonID or
    Person.fathername = Investment.PersonID or
    Person.PersonID = Investment.PersonID
    join Company on Company.CompanyID = Investment.CompanyID
    group by Person.PersonID ;