select section.course_id,section.sec_id,section.semester,section.building,time_slot.day,time_slot.start_hr,time_slot.start_min FROM section JOIN time_slot ON section.time_slot_id=time_slot.time_slot_id WHERE section.year=2010