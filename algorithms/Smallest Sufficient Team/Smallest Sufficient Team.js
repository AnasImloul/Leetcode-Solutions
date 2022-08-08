/**
 * @param {string[]} req_skills
 * @param {string[][]} people
 * @return {number[]}
 */
var smallestSufficientTeam = function(req_skills, people) {
    
    const skillIndexMap = new Map();
    
    req_skills.forEach((skill, index) => skillIndexMap.set(skill,index) );
    
    const skillTeamMap = new Map([[0, []]]);
    
    people.forEach( (skills, index) => {
        
        let hisSkills = 0;
                
        for (const skill of skills) {
            hisSkills |= 1 << skillIndexMap.get(skill);
        }
                
        for (const [currSkill, team] of skillTeamMap) {
            
            const totalSkills = currSkill | hisSkills;
            
            if (totalSkills === currSkill) {
                continue;
            }
            
            if (    
                !skillTeamMap.has(totalSkills) || 
                team.length + 1 < skillTeamMap.get(totalSkills).length
            ) {                
                skillTeamMap.set(totalSkills, [...team, index])
            }             
        }
    });
        
    return skillTeamMap.get( (1<<req_skills.length) - 1);
};
