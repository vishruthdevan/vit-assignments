import math


def knn(points, p, k=3):
    distance = []
    frequencies = {}
    for group in points:
        frequencies[group] = 0
        for point in points[group]:
            euclidean_distance = 0
            for i, j in zip(point, p):
                # calculate the euclidean distance of p from training points
                euclidean_distance += (i-j)**2
            euclidean_distance = math.sqrt(euclidean_distance)
            # Add a tuple of form (distance,group) in the distance list
            distance.append((euclidean_distance, group))
    distance = sorted(distance)[:k]
    for d in distance:
        frequencies[d[1]] += 1
    max = list(frequencies.keys())[0]
    for i in frequencies:
        if frequencies[i] > max:
            max = i
    return max


if __name__ == '__main__':
    knn({}, [],)
