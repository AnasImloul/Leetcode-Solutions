SELECT p.firstName, p.lastName, a.city, a.state FROM Person p  --accessing first hench LEFT
LEFT JOIN Address a USING (personId) -- accessing second hence RIGHT. but we want every row in person so LEFT JOIN.
