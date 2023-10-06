import kotlin.math.PI

fun calculateCylinderVolume(radius: Double, height: Double): Double {
    return PI * radius * radius * height
}

fun main() {
    val radius = 5.0 // Replace with your desired radius
    val height = 10.0 // Replace with your desired height

    val volume = calculateCylinderVolume(radius, height)
    println("The volume of the cylinder is: $volume")
}
