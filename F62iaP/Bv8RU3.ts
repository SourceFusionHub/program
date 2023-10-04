// Calculate area of a rectangle by taking length and breadth from the using typescript
var Rectangle = /** @class */ (function () {
    function Rectangle() {
    }
    Rectangle.prototype.area = function (length, breadth) {
        return length * breadth;
    };
    return Rectangle;
}());
var obj = new Rectangle();
console.log(obj.area(10, 20));
