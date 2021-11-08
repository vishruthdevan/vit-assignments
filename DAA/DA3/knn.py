import math


def knn(points, p, k=3):
    distance = []
    for group in points:
        for point in points[group]:
            euclidean_distance = 0
            for i, j in zip(point, p):
                # calculate the euclidean distance of p from training points
                euclidean_distance += (i-j)**2
            euclidean_distance = math.sqrt(euclidean_distance)
            # Add a tuple of form (distance,group) in the distance list
            distance.append((euclidean_distance, group))
    distance = sorted(distance)[:k]
    freq1 = 0  # frequency of group 0
    freq2 = 0  # frequency og group 1

    for d in distance:
        if d[1] == 'B':
            freq1 += 1
        elif d[1] == 'M':
            freq2 += 1

    return 'B' if freq1 > freq2 else 'M'


if __name__ == '__main__':
    knn()
