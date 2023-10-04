import kotlin.math.sqrt

fun calculateFrustumVolume(upperBaseArea: Double, lowerBaseArea: Double, height: Double): Double {
    val volume = (1.0 / 3.0) * height * (upperBaseArea + lowerBaseArea + sqrt(upperBaseArea * lowerBaseArea))
    return volume
}

fun main() {
    val upperBaseArea = 20.0 // Replace with the actual upper base area
    val lowerBaseArea = 30.0 // Replace with the actual lower base area
    val height = 10.0 // Replace with the actual height
    
    val volume = calculateFrustumVolume(upperBaseArea, lowerBaseArea, height)
    println("The volume of the frustum of the cone is: $volume")
}
