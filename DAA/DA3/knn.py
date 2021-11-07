import math


def knn(points, p, k=3):
    distance = []
    for group in points:
        for feature in points[group]:
            euclidean_distance = 0
            for i, j in zip(feature, p):
                # calculate the euclidean distance of p from training points
                euclidean_distance += (i-j)**2
            euclidean_distance = math.sqrt(euclidean_distance)
            # Add a tuple of form (distance,group) in the distance list
            distance.append((euclidean_distance, group))
