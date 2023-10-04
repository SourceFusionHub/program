import kotlin.math.PI
import kotlin.math.pow

fun calculateSphereVolume(radius: Double): Double {
    val volume = (4.0 / 3.0) * PI * radius.pow(3)
    
    return volume
}

fun main() {
    val radius = 5.0 // Replace with the radius of your sphere
    val volume = calculateSphereVolume(radius)
    
    println("The volume of the sphere with radius $radius is $volume")
}
