SELECT Email from Person
Group By Email
Having Count(*) > 1;
