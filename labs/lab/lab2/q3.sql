SELECT instructor.name FROM instructor JOIN advisor ON instructor.ID=advisor.i_id JOIN student ON student.ID=advisor.s_id WHERE student.dept_name='Comp. Sci.'
