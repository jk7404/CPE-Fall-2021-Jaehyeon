using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class Player : MonoBehaviour
{
    private Rigidbody2D rigidbody;

    private float speed = 3;

    private Animator animator;

    private SpriteRenderer renderer;

    int direction = 0;

    private float horizontal;
    // Start is called before the first frame update 

    // Invoked when a line of data is received from the serial device.
    public void OnMessageArrived(string msg)
    {
        if (msg.Contains("A"))
            direction = -1;
        else if (msg.Contains("C"))
            direction = 1;
        else
            direction = 0;
    }

    // Invoked when a connect/disconnect event occurs. The parameter 'success'
    // will be 'true' upon connection, and 'false' upon disconnection or
    // failure to connect.
    public void OnConnectionEvent(bool success)
    {
        Debug.Log("Connection Status: " + success);
    }

    void Start()
    {
      
        rigidbody = GetComponent<Rigidbody2D>();
        animator = GetComponent<Animator>();
        renderer = GetComponent<SpriteRenderer>();
    }

    // Update is called once per frame
    void Update()
    {
        horizontal = Input.GetAxis("Horizontal"); // moves horizontally
        
        if (GameManager.Instance.stopTrigger)
        {
            animator.SetTrigger("start");
            PlayerMove();
        }
    
        

        if (!GameManager.Instance.stopTrigger)
        {
            animator.SetTrigger("End");
        }

        ScreenChk();
    }

    private void PlayerMove()
    {
        animator.SetFloat("speed", Mathf.Abs(direction)); // Setfloat : give values to float parameter & Mathf.Abs(horizontal) : return the absolute value of horizontal
        if (direction < 0)
        {
            renderer.flipX = true; // flip depending on the direction of the keyboard
        }

        else
        {
            renderer.flipX = false; // flip depending on the direction of the keyboard
        }
        rigidbody.velocity = new Vector2(direction * speed, rigidbody.velocity.y);

    }

    private void ScreenChk()// without this function the Playerobejct will move beyond the game screen and falls down to the position where the ground is not set
    {
        Vector3 worlpos = Camera.main.WorldToViewportPoint(this.transform.position); // Take the value of the location ( x and y ) of world to view point
        if (worlpos.x < 0.05f) worlpos.x = 0.05f; // Constrain the location of the PlayerObject ( x value )
        else if (worlpos.x > 0.95f) worlpos.x = 0.95f;
        this.transform.position = Camera.main.ViewportToWorldPoint(worlpos);
    }
}
