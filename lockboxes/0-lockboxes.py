#!/usr/bin/python3
""" Python Script
"""


def canUnlockAll(boxes):
    """ Function that determines if all the boxes can be opened
    Arguments:
        boxes: list of lists
    Returns:
        True if all boxes can be opened, or False otherwise.
    """
    unlocked_boxes = set([0])

    # indices of the boxes not  checked
    unchecked_boxes = set(range(1, len(boxes)))

    while len(unchecked_boxes) > 0:
        found_new_key = False

        for box_index in unlocked_boxes.copy():
            keys = boxes[box_index]

            # try to unlock a new box
            for key in keys:
                if key in unchecked_boxes:
                    unlocked_boxes.add(key)
                    unchecked_boxes.remove(key)
                    found_new_key = True

        if not found_new_key:
            break

    # Check if we have unlocked all the boxes
    return len(unlocked_boxes) == len(boxes)


if __name__ == "__main__":
    canUnlockAll()
