"use strict";
var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.Graph = void 0;
var MoveGenerator_1 = require("./MoveGenerator");
var Graph = /** @class */ (function () {
    function Graph(start, target) {
        this.start = start;
        this.target = target;
    }
    Graph.prototype.traverse = function () {
        console.log("Start: ".concat(this.start, ", Target: ").concat(this.target));
        var queue = [
            [this.start, [this.start]],
        ];
        var visited = new Set();
        visited.add(JSON.stringify(this.start)); // Mark start as visited
        while (queue.length > 0) {
            var _a = queue.shift(), current = _a[0], path = _a[1]; // Dequeue the front vertex
            console.log("Visiting: ".concat(current, ", Path: ").concat(JSON.stringify(path)));
            if (JSON.stringify(current) === JSON.stringify(this.target)) {
                for (var _i = 0, path_1 = path; _i < path_1.length; _i++) {
                    var step = path_1[_i];
                    console.log(step);
                }
                return path;
            }
            var validMoves = MoveGenerator_1.Moves.getMoves(current);
            for (var _b = 0, validMoves_1 = validMoves; _b < validMoves_1.length; _b++) {
                var move = validMoves_1[_b];
                var moveKey = JSON.stringify(move);
                if (!visited.has(moveKey)) {
                    visited.add(moveKey);
                    queue.push([move, __spreadArray(__spreadArray([], path, true), [move], false)]);
                }
            }
        }
        console.log(" No path found.");
        return [];
    };
    return Graph;
}());
exports.Graph = Graph;
