#!/usr/bin/python3
def square_matrix_simple(matrix=[]):
    result = [];
    for rows in matrix:
        new_row = [];
        for item in rows:
            new_row.append(item * item);

        result.append(new_row);

    return result;
