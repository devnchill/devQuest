"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Moves = void 0;
var Moves = /** @class */ (function () {
    function Moves() {
    }
    Moves.isValid = function (vertex) {
        var x = vertex[0], y = vertex[1];
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    };
    Moves.findNextMoves = function (vertex) {
        var positions = [];
        var x = vertex[0], y = vertex[1];
        var i = 0;
        var deltaCoor = [
            [2, 1],
            [2, -1],
            [-2, 1],
            [-2, -1],
            [1, 2],
            [1, -2],
            [-1, 2],
            [-1, -2],
        ];
        while (i < 8) {
            var _a = deltaCoor[i], dx = _a[0], dy = _a[1];
            var newMove = [x + dx, y + dy];
            if (this.isValid(newMove)) {
                positions.push(newMove);
            }
            i++;
        }
        return positions;
    };
    Moves.getMoves = function (vertex) {
        return this.findNextMoves(vertex);
    };
    return Moves;
}());
exports.Moves = Moves;
