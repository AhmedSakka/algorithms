def numberOfBeams(bank: list[str]) -> int:
	result = 0
	previous_row = 0

	for row in bank:
		beams = row.count('1')
		if beams:
			result += beams * previous_row
			previous_row = beams

	return result

bank_plan = ["011001","000000","010100","001000"]

beams_count = numberOfBeams(bank_plan)

print(f"The bank has {beams_count} laser beams")