#!/usr/bin/python3
"""
Log parsing script that reads stdin line by line and computes metrics.
"""
import sys

# Initialize variables
codes = {}
status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
count = 0
size = 0


def print_statistics(size, codes):
    print("File size: {}".format(size))
    for key in sorted(codes):
        print("{}: {}".format(key, codes[key]))


if __name__ == "__main__":
    try:
        for ln in sys.stdin:
            if count == 10:
                print_statistics(size, codes)
                count = 1
            else:
                count += 1

            ln = ln.split()

            try:
                size = size + int(ln[-1])
            except (IndexError, ValueError):
                pass

            try:
                if ln[-2] in status_codes:
                    if ln[-2] not in codes:
                        codes[ln[-2]] = 1
                    else:
                        codes[ln[-2]] += 1
            except IndexError:
                pass

        print_statistics(size, codes)

    except KeyboardInterrupt:
        print_statistics(size, codes)
        raise
