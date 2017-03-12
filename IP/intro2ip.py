# from here: https://blog.remix.com/an-intro-to-integer-programming-for-engineers-simplified-bus-scheduling-bd3d64895e92#.2fr1175q6

def generate_trips(route_names, start_hour, end_hour):
	results = []
	for route_name in route_names:
		for hour in range(start_hour,end_hour):
			results.append((route_name,hour))
	return results